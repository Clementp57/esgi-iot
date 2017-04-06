/* REST DELETE
Suprime une présence existante grâce à son identifiant

route: DELETE /presences/{presence_id}

Les codes HTTP :
- 204 : Requête traitée avec succès mais pas d’information à renvoyer
- 404 : Ressource non trouvée
- 500 : Erreur interne du serveur
OK
*/

module.exports = function(app) {
	return function(req, res, next) {
		
		var Presence = app.models.Presence;
		
		Presence.remove({},function(err, result) {
			if(err || !result){
				return res.status(500).json('Erreur interne du serveur');
			}

			res.status(204).json({success: true});
		});
		
	};
};
