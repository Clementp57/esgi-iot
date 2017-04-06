/**
 * REST CREATE
 * Créer une solution lumineuse
 *
 * route: POST /presences
 *
 * Les codes HTTP :
 *	- 201 : Requête traitée avec succès et création de document
 *	- 400 : Mauvaise requête
 *	- 403 : Accès refusé
 *	- 500 : Erreur interne du serveur
 */

var moment = require('moment-timezone');

module.exports = function(app) {
	return function(req, res, next) {

		if(!req.body){
			return res.status(400).json({success: false, error: 'Paramètres manquants ou inconnus'});
		}

		var value = 1;
		var device = 'test';
		var today = moment().tz('Europe/Paris').format(); 
		if(typeof req.body.value !== 'undefined'){
			value = req.body.value;
		}

		if(typeof req.body.value !== 'undefined'){
			value = req.body.value;
		}

		if(typeof req.body.device_name !== 'undefined'){
			device = req.body.device;
		}

		var Presence = app.models.Presence;
		var presence = new Presence({
			presence_trigger_date: today,
			presence_value: value,
			device_name: device
		});

		// Sauvegarde dans la base de donnée
		presence.save(function(err, result) {
			
			if(err || !result){
				throw err;
				return res.status(500).json({success: false, error: 'Erreur interne du serveur'});
			}

			res.status(201).json({success: true, _id: result._id});
		});
	};
};