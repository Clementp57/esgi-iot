# Serveur en nodejs

## Mise en place du serveur

Installer les libs :
```
npm install

ou

npm install body-parser --save
npm install mongoose --save
npm install mongodb --save
npm install nodemon --save-dev
npm install express --save
```


Lancer mongodb avec :
```
brew services start mongodb
```

Lancer le server avec :
```
nodemon app/index.js

ou

node app.index.js
```

## Requêtes HTTP

POST
```
http://localhost:8080/presences

JSON :
> device_name (text)(optionnel)
> value (int)(optionnel)
```

GET
```
http://localhost:8080/presences
```

DELETE (Supprime toutes les présences)
```
http://localhost:8080/presences
```
