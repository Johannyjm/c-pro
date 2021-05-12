#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        _a: i32, 
        b: i32, 
        c: i32, 
        _d: i32
    }

    println!("{}", b-c);
}
