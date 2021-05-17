#![allow(unused_imports, non_snake_case)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

#[fastout]
fn main() {
    input! {
        n: usize, 
        a: [i32; n]
    }

    let mut cnt = [0; 440];
    for mut e in a {
        e += 200;
        cnt[e as usize] += 1;
    }

    let mut res = 0;
    for i in 0..401 {
        for j in 0..401 {
            if i >= j {
                continue;
            }
            let l = i as isize - 200;
            let r = j as isize - 200;
            res += (l - r) * (l - r) * cnt[i] * cnt[j];
        }
    }

    println!("{}", res);

}
