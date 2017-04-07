
// Fichier index qui redirige vers les autres fichiers du dossier
module.exports = function(app) {
	app.actions = {
		presences : require('./presences')(app)
	};
};
