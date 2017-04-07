package com.esgi.iot_presence;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.esgi.iot_presence.models.Presence;
import com.esgi.iot_presence.server.ServerHandler;
import com.esgi.iot_presence.server.VolleyCallBack;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = MainActivity.class.getSimpleName();
    ServerHandler serverHandler;
    ListView list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);

        list = (ListView) findViewById(R.id.list_presence);


        serverHandler = ServerHandler.getInstance(MainActivity.this);
        getPresenceList();

        assert fab != null;
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getPresenceList();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    private void getPresenceList() {

        final ProgressDialog progress = new ProgressDialog(this);
        progress.setMessage("Chargement");

        serverHandler.getPresencesList(new VolleyCallBack() {

            @Override
            public void onSuccess(Object response) {
                progress.dismiss();
                JSONObject object = (JSONObject) response;
                try {

                    ArrayList<Presence> presencesList = new ArrayList<>();

                    JSONArray array = object.getJSONArray("list");
                    Log.i(TAG, "onSuccess: value : " + array.toString());
                    for (int i = array.length()-10; i < array.length(); i++) {
                        JSONObject obj = array.getJSONObject(i);
                        Log.i(TAG, "onSuccess: device : " + obj.getString("date"));

                        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss", Locale.FRANCE);
                        SimpleDateFormat formatterOut = new SimpleDateFormat("dd MMM yyyy hh:mm:ss", Locale.FRANCE);
                        Date presenceDate;
                        String presenceDateTime;
                        try {
                            presenceDate = formatter.parse(obj.getString("date"));
                            presenceDateTime = formatterOut.format(presenceDate);
                        } catch (ParseException e) {
                            presenceDateTime = "Date non récupérée";
                        }
                        Log.i(TAG, "onSuccess: Date : " + presenceDateTime);
                        Presence presence = new Presence();
                        presence.setPresenceDate(presenceDateTime);
                        presence.setCount(String.valueOf(obj.getInt("count")));
                        presencesList.add(presence);
                        Log.i(TAG, "onSuccess: value : " + obj.getInt("count"));
                    }
                    PresenceListAdapter adapter = new PresenceListAdapter(MainActivity.this, presencesList);
                    list.setAdapter(adapter);

                } catch (JSONException e) {
                    e.printStackTrace();
                    progress.dismiss();
                }
            }

            @Override
            public void onError(int errorCode) {
                progress.dismiss();
            }
        });
    }

    private class PresenceListAdapter extends BaseAdapter {

        private Context context;
        private ArrayList<Presence> presences;
        private LayoutInflater layoutInflater;
        private ViewHolderPresence viewHolderPresence;

        public PresenceListAdapter(Context context, ArrayList<Presence> presences) {
            this.context = context;
            this.presences = presences;
        }

        @Override
        public int getCount() {
            return presences.size();
        }

        @Override
        public Object getItem(int position) {
            return presences.get(position);
        }

        @Override
        public long getItemId(int position) {
            return position;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            if (convertView == null) {

                layoutInflater = LayoutInflater.from(context);
                convertView = layoutInflater.inflate(R.layout.row_presence, null);
                viewHolderPresence = new ViewHolderPresence();
                viewHolderPresence.date = (TextView) convertView.findViewById(R.id.text_date);
                viewHolderPresence.count = (TextView) convertView.findViewById(R.id.text_count);
                convertView.setTag(viewHolderPresence);
            } else {
                viewHolderPresence = (ViewHolderPresence) convertView.getTag();
            }

            // Si la liste des lieux est vide on affiche alors un message indiquant que la catégorie est vide
            if (presences != null) {
                viewHolderPresence.date.setText(presences.get(position).getPresenceDate());
                viewHolderPresence.count.setText(presences.get(position).getCount());
            }
            return convertView;
        }

        class ViewHolderPresence {
            TextView date, count;
        }
    }

}
