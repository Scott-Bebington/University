import { Component, OnInit } from '@angular/core';
import {fact} from '../Interfaces/fact';
import {FactsService} from '../Services/facts.service';
import {HttpClient, HttpParams, HttpHeaders} from '@angular/common/http';
import {Observable} from 'rxjs';

@Component({
  selector: 'app-facts',
  templateUrl: './facts.component.html',
  styleUrls: ['./facts.component.css'],
  providers: [FactsService]
})
export class FactsComponent implements OnInit {

    numFacts:number = 0;
    facts:fact[] = [];
    endpoint:string = 'https://uselessfacts.jsph.pl/';
	random:string = 'random'; //To use the random endpoint
	added:string = '.json?language=en'; //Added to the end of the request

  constructor(private factsSer:FactsService) {
  
   }
    
  ngOnInit(): void {
  }


   getRandom(): void
   {
   	this.facts = [];
/*   	this.facts.push({id:'0', text: 'This is the very first fact', source: 'Myself'});
   	this.facts.push({id:'1', text: 'This is a useful way of looping through items', source: 'Angular docs I think'}); */


	for (var i =0;i<this.numFacts;i++)
	{
		this.factsSer.getRandomJokes().subscribe( (data) => {
			this.facts.push({id : data.id, source: data.source, text: data.text});
		});
	}   	
	
   	
   }



}
