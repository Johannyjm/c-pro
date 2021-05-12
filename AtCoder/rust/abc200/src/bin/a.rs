use proconio::{input, fastout};

#[fastout]
fn main() {
    input!{
        n: i32
    }

    let mut res = n / 100;
    if n % 100 != 0{
        res += 1;
    }

    println!("{}", res);
}
