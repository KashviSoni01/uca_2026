import java.util.*;

public class ClinicAndVillage {

    static class Triplet {
        double avgLoad;
        int population;
        int clinics;
    
    Triplet(double avgLoad, int population, int clinics) {
        this.avgLoad = avgLoad;
        this.population = population;
        this.clinics = clinics;

    }
}
    public static double findMinimumMaximumLoad(int[] population, int k) {
        if(k<population.length) return -1;

        //max heap for storing load
        PriorityQueue<Triplet> pq = new PriorityQueue<>((a, b) -> Double.compare(b.avgLoad, a.avgLoad));
        k-=population.length;
        

        for(int i=0; i<population.length; i++) {
            pq.add(new Triplet(population[i], population[i], 1));
        }
        while(k!=0) {
            Triplet curr = pq.poll();
            int p=curr.population;
            int c=curr.clinics;
          double a = (double) p / (c + 1);
            pq.add(new Triplet(a,p,c+1));
            k--;
        }


        return pq.peek().avgLoad;
    }

    public static void main(String[] args) {

        int[] population = {200, 20, 50};
        int k = 5;

        double result = findMinimumMaximumLoad(population, k);

        System.out.printf("%.2f%n", result);
    }
}
