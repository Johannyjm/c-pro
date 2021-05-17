#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input! {
        n: usize
    }

    let mut res: f64 = 0.;
    for i in 1..n+1 {
        res += 1f64 / i as f64;
    }
    res *= n as f64;
    res -= 1.0f64;

    println!("{}", res);

}
