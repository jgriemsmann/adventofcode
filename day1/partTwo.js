'use strict';

const fs = require('fs');

let inputs = fs.readFileSync('input.txt', 'utf-8').split('\n');
inputs = inputs.map(Number);

inputs.forEach(firstInput => {
  inputs.forEach(secondInput => {
    inputs.forEach(thirdInput => {
      if (firstInput + secondInput + thirdInput === 2020) {
        console.log(firstInput * secondInput * thirdInput);
      }
    });
  });
});
