const user32 = require('bindings')('user32.node');

test('get async key status', () => {
    let state = user32.getAsyncKeyState(1);
    expect([0, 1, -32767]).toContain(state);
});

test('find window.', () => {
    let handle = user32.a.findWindow(null, null);
    expect(handle).toBeGreaterThan(0);
})