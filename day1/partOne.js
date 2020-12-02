'use strict';

const fs = require('fs');

let inputs = fs.readFileSync('input.txt', 'utf-8').split('\n');
inputs = inputs.map(Number);

inputs.forEach(firstInput => {
  inputs.forEach(secondInput => {
    if (firstInput + secondInput === 2020) {
      console.log(firstInput * secondInput);
    }
  });
});
