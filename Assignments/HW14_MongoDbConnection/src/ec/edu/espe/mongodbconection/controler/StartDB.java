/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.mongodbconection.controler;

import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.Mongo;
import ec.edu.espe.mongodbconection.view.FrmAddUser;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Andres Garcia
 */
public class StartDB {
    
    private DB db;
    public DBCollection tabla;
    
    public void conect(){
        try {
            Mongo mongo = new Mongo("localhost",27017);
            db = mongo.getDB("database");
            tabla = db.getCollection("tabla");
        } catch (UnknownHostException ex) {
            Logger.getLogger(FrmAddUser.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    }
}
