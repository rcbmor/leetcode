/**
 * LeetCode problem 3484
 * https://leetcode.com/problems/design-spreadsheet/
 */

#![allow(dead_code)]
#![allow(unused_variables)]

use std::collections::HashMap;

struct Spreadsheet {
    table: HashMap<String,i32>,

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Spreadsheet {

    fn new(rows: i32) -> Self {
        Spreadsheet{
            table: HashMap::new()
        }
    }
    
    fn set_cell(&mut self, cell: String, value: i32) {
        self.table.insert(cell, value);
    }

    fn get_cell(&self, cell: String) -> i32 {
        match self.table.get(&cell.to_string()) {
            Some(v) => *v,
            None => 0
        }
    }
    
    fn reset_cell(&mut self, cell: String) {
        self.table.insert(cell, 0);        
    }
    
    fn get_value(&self, formula: String) -> i32 {
        let f = formula[1..].to_string();
        let Some((first, second)) = f.split_once('+') else {todo!()};

        let v1: i32 = if first.chars().nth(0).unwrap().is_digit(10) {
            first.parse().unwrap()
        } else {
            self.get_cell(first.to_string())
        };

        let v2: i32 = if second.chars().nth(0).unwrap().is_digit(10) {
            second.parse().unwrap()
        } else {
            self.get_cell(second.to_string())
        };

        v1 + v2
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * let obj = Spreadsheet::new(rows);
 * obj.set_cell(cell, value);
 * obj.reset_cell(cell);
 * let ret_3: i32 = obj.get_value(formula);
 */
fn main() {
    println!("Hello, world!");

// Input:
// ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
// [[3],            ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

// Output:
// [null, 12, null, 16, null, 25, null, 15] 

    let mut s = Spreadsheet::new(3);
    let mut f = "=5+7";
    let mut r = s.get_value(f.to_string());
    println!("> get_value({}) = {}", f, r);

    s.set_cell("A1".to_string(), 10);
    println!("> set_cell(A1, 10) = {}", s.get_cell("A1".to_string()));

    f = "=A1+6";
    r = s.get_value(f.to_string());
    println!("> get_value({}) = {}", f, r);

    s.set_cell("B2".to_string(), 15);
    println!("> set_cell(B2, 15) = {}", s.get_cell("B2".to_string()));

    f = "=A1+B2";
    r = s.get_value(f.to_string());
    println!("> get_value({}) = {}", f, r);

    s.reset_cell("A1".to_string());
    println!("> reset_cell(A1) = {}", s.get_cell("A1".to_string()));

    f = "=A1+B2";
    r = s.get_value(f.to_string());
    println!("> get_value({}) = {}", f, r);

    f = "=O126+10272";
    r = s.get_value(f.to_string());
    println!("> get_value({}) = {}", f, r);
}
