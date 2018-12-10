const http = require('http'); // call the module which create server
http.createServer((request, response) => { // method which create server
  console.log('server start!');
}).listen(8080);