const addon = require('./build/Release/array_sum');

const big = Array.from({length: 1000000}, (_, i) => i + 1);
const sum = addon.sum(big);
console.log('Resultado:', sum);

