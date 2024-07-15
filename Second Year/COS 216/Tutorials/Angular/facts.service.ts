import {Injectable} from '@angular/core';
import {HttpClient, HttpParams, HttpHeaders} from '@angular/common/http';
import {Observable} from 'rxjs';


@Injectable()
export class FactsService
{

	endpoint:string = 'https://uselessfacts.jsph.pl/';
	random:string = 'random'; //To use the random endpoint
	added:string = '.json?language=en'; //Added to the end of the request
	constructor(private http:HttpClient)
	{
	}
	
	getRandomJokes():Observable<any>
	{
		return this.http.get(this.endpoint+this.random+this.added);
	}

}
