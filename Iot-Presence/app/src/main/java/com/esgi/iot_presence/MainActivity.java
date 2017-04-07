package com.esgi.iot_presence;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.esgi.iot_presence.server.ServerHandler;
import com.esgi.iot_presence.server.VolleyCallBack;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = MainActivity.class.getSimpleName();

    ListView list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        list = (ListView) findViewById(R.id.list_presence);


        ServerHandler serverHandler = ServerHandler.getInstance(MainActivity.this);
        serverHandler.getPresencesList(new VolleyCallBack() {

            @Override
            public void onSuccess(Object response) {
                JSONObject object = (JSONObject) response;
                try {
                    ArrayList<String> presencesList = new ArrayList<>();
                    JSONArray array = object.getJSONArray("list");
                    Log.i(TAG, "onSuccess: value : " + array.toString());
                    for(int i=0; i<array.length(); i++){
                        JSONObject obj = array.getJSONObject(i);
                        Log.i(TAG, "onSuccess: device : " + obj.getString("presence_trigger_date"));
                        presencesList.add(obj.getString("presence_trigger_date"));
                        Log.i(TAG, "onSuccess: device : " + obj.getString("device_name"));
                        Log.i(TAG, "onSuccess: value : " + obj.getInt("presence_value"));
                    }
                    ArrayAdapter<String> adapter = new ArrayAdapter<>(MainActivity.this, android.R.layout.simple_list_item_2, presencesList);
                    list.setAdapter(adapter);

                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void onError(int errorCode) {

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
}
