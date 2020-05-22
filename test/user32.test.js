const user32 = require(__dirname + '/../build/Release/user32');

test('get async key status', () => {
    let state = user32.getAsyncKeyState(1);
    expect([0, 1, -32767]).toContain(state);
});