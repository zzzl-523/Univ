package lab04;

public class City {
	private String name;
	private int location_x=0;
	private int location_y=0;
	
	City(String name, int location_x, int location_y) {	//持失切
		this.name=name;
		this.location_x=location_x;
		this.location_y=location_y;
	}
	City(String name){	//持失切
		this.name=name;
		this.location_x=(int) (Math.random()*360);
		this.location_y=(int)(Math.random()*360);
	}
	public String getName() {	//getter持失
		return name;
	}
	public int getLocation_x() {
		return location_x;
	}
	public int getLocation_y() {
		return location_y;
	}
	
	public boolean equals(City A) {
		if(this.name.equals(A.name)&&this.location_x==A.location_x&&this.location_y==A.location_y){
			return true;
		}
		else return false;
	}
	public String toString() {
		return(this.name+", "+this.location_x+", "+this.location_y);
	}
	
	public static double distance(City A, City B) {
		return Math.sqrt( (Math.pow((A.location_x-B.location_x),2)	+	Math.pow((A.location_y-B.location_y),2)));
	}
	
	
	
}
