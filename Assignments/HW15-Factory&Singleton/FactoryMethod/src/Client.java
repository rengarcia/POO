/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Andres Garcia
 */
public class Client {
    public static void main(String[] args) {
        Factory factory;
        factory = new FactoryOne();
        Connection connection = factory.creatConnection("Oracle");
        System.out.println("You are connectin with " + connection.description());
    }    
}
