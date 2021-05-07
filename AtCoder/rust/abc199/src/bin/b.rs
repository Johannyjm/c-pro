use proconio::{input, fastout};

#[fastout]
fn main() {
    input!{
        n: usize,
        a: [i64; n], 
        b: [i64; n]
    }
    let mut mxa = 0;
    let mut mnb = 1001001001;
    for i in 0..n {
        if a[i] > mxa{
            mxa = a[i];
        }
        if b[i] < mnb{
            mnb = b[i];
        }
    }

    println!("{}", (mnb - mxa + 1).max(0));
}
