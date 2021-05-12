#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        m: i32, 
        h: i32
    }

    if h % m == 0{
        println!("Yes");
    }
    else{
        println!("No");
    }
}
