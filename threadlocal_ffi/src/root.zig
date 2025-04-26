threadlocal var t_val: u32 = 0;

pub export fn set(val: u32) callconv(.C) void {
    t_val = val;
}

pub export fn get() callconv(.C) u32 {
    return t_val;
}
