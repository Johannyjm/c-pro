use proconio::{input, fastout};

#[fastout]
fn main() {
    input! {
        n: i64, 
        k: i64
    }

    let mut now = n;
    for _ in 0..k{
        if now % 200 == 0{
            now /= 200;
        }
        else{
            now = now * 1000 + 200;
        }
    }

    println!("{}", now);
}
