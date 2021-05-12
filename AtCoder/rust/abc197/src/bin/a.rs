use proconio::{input, fastout, marker::Chars};

#[fastout]
fn main() {
    input!{
        s: Chars
    }
    
    println!("{}{}{}", s[1], s[2], s[0]);
}
