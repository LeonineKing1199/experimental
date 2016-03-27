'use strict';

const koa = require('koa');

let app = koa();

// x-response-time
app.use(function* (next) {
  let start = new Date;
  yield next;
  let ms = new Date - start;
  this.set(`X-response-time ${ms} ms`);
});

// logger
app.use(function* (next) {
  let start = new Date;
  yield next;
  let ms = new Date - start;
  console.log(`${this.method} ${this.url} ${ms}`);
});

app.use(function* () {
  this.body = 'Hello, world!';
});

app.listen(3000);
