/*
Modèle pour l'activation du capteur infrarouge
- presence_trigger_date : date de passage d'un individu
*/
module.exports = function(app) {
	var presenceSchema = app.mongoose.Schema({
		presence_trigger_date: { type: Date, required: true },
    presence_value: { type: Number, required: true },
    device_name: { type: String, required: true },
	});

	var Presence = app.mongoose.model('Presence', presenceSchema);

	return Presence;
};
