#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        n: i64
    }
    
    let mut left: i64 = 1;
    let mut right: i64 = 999;

    let mut res: i64 = 0;
    let mut base: i64 = 0;

    loop {
        if left <= n && n <= right{
            res += base * (n-left+1);
            break;
        }
        else{
            res += base * (right-left+1);
            left *= 1000;
            right = right*1000 + 999;
            base += 1;
        }
    }

    println!("{}", res);
}
