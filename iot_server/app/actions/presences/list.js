/* REST GET
Récupérer toutes les présences

route: GET /presences

Les codes HTTP :
- 200 : Requête traitée avec succès
- 404 : Ressource non trouvée
- 500 : Erreur interne du serveur
OK
*/

module.exports = function(app) {
	return function(req, res, next) {
		var Presence = app.models.Presence;

		Presence.find(function(err, presences) {
			if(err){
        	return res.status(500).json({success: false, error: 'Erreur interne du serveur'});
      	}

		if(!presences){
			return res.status(404).json({success: false, error: 'Liste de présences vide'});
		}

			res.status(200).json({success: true, list: presences});
		});
	};
};
