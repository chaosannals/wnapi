const kernel32 = require('bindings')('kernel32.node');

test('get current thread id', () => {
    let tid = kernel32.getCurrentThreadId();
    expect(tid).toBeGreaterThan(0);
});

test('get current process id', () => {
    let pid = kernel32.getCurrentProcessId();
    expect(pid).toBeGreaterThan(0);
});

test('psapi', () => {
    let ids = kernel32.enumProcesses();
});

test('tlhelp', () => {
    let handle = kernel32.createToolhelp32Snapshot(2, 0);
    let info1 = kernel32.a.process32First(handle);
    let info2 = kernel32.a.process32Next(handle);
});