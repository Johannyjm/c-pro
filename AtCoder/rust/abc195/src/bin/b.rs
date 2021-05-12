#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input!{
        a: i32, 
        b: i32, 
        mut w: i32
    }

    w *= 1000;

    let mut res1 = 1001001001;
    let mut res2 = 0;
    for i in 1..1000001{
        if a*i <= w && w <= b*i{
            res1 = std::cmp::min(res1, i);
            res2 = std::cmp::max(res2, i);
        }
    }

    if res1==1100 || res2==0{
        println!("UNSATISFIABLE");
    }
    else{
        println!("{} {}", res1, res2);
    }
    
}
