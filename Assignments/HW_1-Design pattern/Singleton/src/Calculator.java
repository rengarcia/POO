/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Andres Garcia
 */
public class Calculator {
    public static void main(String[] args) {
        USTax tax = USTax.getInstance();
        System.out.println(tax.saleTotal());
    }
    
}