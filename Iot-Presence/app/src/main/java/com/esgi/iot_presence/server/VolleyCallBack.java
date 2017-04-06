package com.esgi.iot_presence.server;

/**
 * Interface servant de callback pour les réponses du serveur.
 * <p/>
 * Created by sylvainvincent on 26/03/2017.
 */
public interface VolleyCallBack {

    void onSuccess(Object response);
    void onError(int errorCode);

}
