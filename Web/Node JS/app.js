import { read } from 'fs';

//




var http = require('http');
var fs = require('fs');


var server = http.createServer(function(req, res){

    if(req.url == "/"){
        fs.readFile('index.html', function(err, data){
            res.write(data);
            res.end('index bitti');
        });
    }

    if(req.url == "/login"){
        fs1.readFile('login.html', function(err, data){
            res.write(data);
            res.end('login bitti');
        });
    }
    console.log(req.url);

});


server.listen(8000);