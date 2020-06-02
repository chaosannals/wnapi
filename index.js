const kernel32 = require('bindings')('kernel32.node');
const user32 = require('bindings')('user32.node');

module.exports = {
    kernel32: kernel32,
    user32: user32,
};