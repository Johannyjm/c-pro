#[allow(unused_imports)]
use proconio::{
    input, fastout,
    marker::{Chars, Bytes, Usize1}
};

fn digit(mut n: i64) -> i64{
    let mut ret: i64 = 1;
    // let mut tmp = n;
    while(n > 0){
        n /= 10;
        ret *= 10;
    }
    return ret;
}

#[fastout]
fn main() {
    input!{
        n: i64
    }

    let mut res = 0;
    for i in 1..4000000{
        let d: i64 = digit(i);
        let num = i * d + i;

        if num <= n{
            res += 1;
        }
        else{
            break;
        }
    }
    println!("{}", res);
}
