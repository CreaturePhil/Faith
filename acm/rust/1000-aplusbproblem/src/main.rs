// 1000. A+B Problem
//
// http://acm.timus.ru/problem.aspx?space=1&num=1000
//
// Calculate a + b
//
// Input
// a and b
//
// Output
// a+b
//
// Sample
// input    output
// 1 5      6

use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .ok()
        .expect("Failed to read line");

    println!("{}", adder(input));
}

fn adder(input: String) -> i32 {
    let nums: Vec<&str> = input.trim().split(' ').collect();
    let a: i32 = match nums[0].parse() {
        Ok(num) => num,
        Err(_) => 0,
    };
    let b: i32 = match nums[1].parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    a + b
}

#[test]
fn it_works() {
    assert_eq!(adder("1 1".to_string()), 2);
    assert_eq!(adder("1 5".to_string()), 6);
    assert_eq!(adder("349 1273".to_string()), 1622);
}
