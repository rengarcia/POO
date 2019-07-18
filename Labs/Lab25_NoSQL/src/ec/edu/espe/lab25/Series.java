/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.lab25;

/**
 *
 * @author Andres Garcia
 */
public class Series {
    private String title;
    private String genre;
    private int year;
    private float rttRating;
    private String Studio;
    private int seasons;
    

    public Series(String title, String genre, int year, float rttRating, String Studio, int seasons) {
        this.title = title;
        this.genre = genre;
        this.year = year;
        this.rttRating = rttRating;
        this.Studio = Studio;
        this.seasons = seasons;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public float getRttRating() {
        return rttRating;
    }

    public void setRttRating(float rttRating) {
        this.rttRating = rttRating;
    }

    public String getStudio() {
        return Studio;
    }

    public void setStudio(String Studio) {
        this.Studio = Studio;
    }

    public int getSeasons() {
        return seasons;
    }

    public void setSeasons(int seasons) {
        this.seasons = seasons;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    
   

    
    

}

