const kernel32 = require(__dirname + '/../build/Release/kernel32');

test('get current thread id', () => {
    let tid = kernel32.getCurrentThreadId();
    expect(tid).toBeGreaterThan(0);
});

test('get current process id', () => {
    let pid = kernel32.getCurrentProcessId();
    expect(pid).toBeGreaterThan(0);
});

test('find window.', () => {
    let handle = kernel32.a.findWindow(null, null);
    expect(handle).toBeGreaterThan(0);
})