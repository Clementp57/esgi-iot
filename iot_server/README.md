#Mise en place du serveur

##Installer les libs

```
npm install body-parser --save
npm install mongoose --save
npm install mongodb --save
npm install nodemon --save-dev
npm install express --save
```


Lancer mongodb avec :
```
brew services restart mongodb
```

Lancer le server avec : 
```
nodemon app/index.js

ou

node app.index.js
```