use proconio::{
    input, fastout, 
    marker::{Bytes, Chars, Usize1}
};

#[fastout]
fn main() {
    input!{
        n: usize, 
        mut s: Chars, 
        q: usize, 
        l: [(usize, usize, usize); q]
    }

    let mut sl: [Chars; n];
    for i in 0..n{
        sl[i] = s[i];
    }


    let mut flip = false;

}
