#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        n: usize, 
        ab: [(i32, i32); n]
    }

    let mut res = 1001001001;
    for i in 0..n {
        for j in 0..n {
            let time = if i==j {
                ab[i].0 + ab[j].1
            } else {
                std::cmp::max(ab[i].0, ab[j].1)
            };
            res = std::cmp::min(res, time);
        }
    }

    println!("{}", res);

}
