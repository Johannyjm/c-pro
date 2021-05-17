#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        a: i32, 
        b: i32
    }
    let c = a + b;

    println!("{}", if c >= 15 && b >= 8 {
        1
    } else if c >= 10 && b >= 3 {
        2
    } else if c >= 3 {
        3
    } else {
        4
    });
}
