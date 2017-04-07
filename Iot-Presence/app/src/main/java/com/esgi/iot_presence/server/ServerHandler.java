package com.esgi.iot_presence.server;

import android.content.Context;
import android.util.Log;

import com.android.volley.AuthFailureError;
import com.android.volley.NetworkError;
import com.android.volley.ParseError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.ServerError;
import com.android.volley.TimeoutError;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

/**
 * Classe permettant de communiquer avec le serveur.
 * <p/>
 * Created by sylvainvincent on 6/04/2017.
 */
public class ServerHandler {

    private final String TAG = getClass().getSimpleName();

 //   private static final String API_BASE_URL = "http://192.168.1.16:8080/"; // device WIFI
    private static final String API_BASE_URL = "http://192.168.43.168:8080/"; // device 4G
    // private static final String API_BASE_URL = "http://10.0.2.2:8080/"; // emulator

    private static final String SUB_CATEGORY_AUTHENTICATION = "presences/";
    private final Context CONTEXT;
    private final int ERROR_CODE_UNAVAILABLE_SERVER = 1;
    private final int ERROR_CODE_OTHER = 2;

    private static ServerHandler serverHandlerInstance;
    private RequestQueue requestQueue;
    private final int CONNECTION_RETRY_MAX = 3;
    private int connectionCount = 0;

    private ServerHandler(Context context) {
        this.CONTEXT = context;
        this.requestQueue = getRequestQueue();
    }

    public static synchronized ServerHandler getInstance(Context context) {
        if (serverHandlerInstance == null) {
            serverHandlerInstance = new ServerHandler(context);
        }
        return serverHandlerInstance;
    }

    /**
     * Permet de se connecter à l'application grace à des identifiants
     *
     * @param callback fonction de callback
     */
    public void getPresencesList(final VolleyCallBack callback) {

        JsonObjectRequest jsonArrayRequest = new JsonObjectRequest(Request.Method.GET,
                API_BASE_URL + SUB_CATEGORY_AUTHENTICATION,
                null,
                new Response.Listener<JSONObject>() {

                    @Override
                    public void onResponse(JSONObject response) {
                        try {
                            if (response.getBoolean("success")) {
                                Log.i(TAG, "onResponse " + response.toString());
                                callback.onSuccess(response);

                            }

                        } catch (JSONException e) {
                            e.printStackTrace();
                        }


                    }

                }, new Response.ErrorListener() {

            @Override
            public void onErrorResponse(VolleyError error) {

                Log.e(TAG, "onErrorResponse : " + error.getNetworkTimeMs());

                if( error instanceof NetworkError) {

                    Log.e(TAG, "onErrorResponse NetworkError: " + error.getMessage());
                    callback.onError(ERROR_CODE_OTHER);

                } else if( error instanceof ServerError) {

                    Log.e(TAG, "onErrorResponse ServerError: " + error.getMessage());
                    callback.onError(ERROR_CODE_OTHER);

                } else if( error instanceof AuthFailureError) {

                    Log.e(TAG, "onErrorResponse AuthFailureError: " + error.getMessage());
                    callback.onError(ERROR_CODE_OTHER);

                } else if( error instanceof ParseError) {

                    Log.e(TAG, "onErrorResponse: ParseError " + error.getMessage());
                    callback.onError(ERROR_CODE_OTHER);

                } else if( error instanceof TimeoutError) {

                    connectionCount++;
                    if (connectionCount >= CONNECTION_RETRY_MAX) {

                        connectionCount = 0;
                        Log.e(TAG, "Temps de connexion écoulé " + error.getMessage());
                        callback.onError(ERROR_CODE_UNAVAILABLE_SERVER);

                    } else {

                        Log.e(TAG, "Temps écoulé, relance de la requête");
                        getPresencesList(callback);

                    }

                } else {
                    Log.e(TAG, "onErrorResponse: " + error.getMessage());
                    callback.onError(ERROR_CODE_OTHER);
                }

            }
        });

        // Ajoute la requête à la file
        getRequestQueue().add(jsonArrayRequest);

    }

    public void cancelPendingRequests(Object tag) {
        if (requestQueue != null) {
            requestQueue.cancelAll(tag);
        }
    }

    private RequestQueue getRequestQueue() {
        if (requestQueue == null) {
            requestQueue = Volley.newRequestQueue(CONTEXT.getApplicationContext());
        }
        return requestQueue;
    }

}
