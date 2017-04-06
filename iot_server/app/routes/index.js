// Fichier index qui redirige vers les autres fichiers du dossier
module.exports = function(app) {
	app.use('/presences', require('./presences')(app));

};
