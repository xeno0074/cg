const { performance } = require('perf_hooks');
const nemo = ['nemo'];
const large = new Array(100000).fill('nemo');

function findNemo(array) {

    let time = performance.now();
    for (let i = 0; i < array.length; ++i) {
        if (array[i] === 'nemo') {
            console.log('found nemo');
        }
    }
    time = performance.now() - time;

    console.log('time taken: ' + time + ' ms')
}

findNemo(large);