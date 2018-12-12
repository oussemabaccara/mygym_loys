#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "offre.h"
#include "event.h"
#include "seancee.h"
#include "consultm.h"
#include "consultc.h"


void
on_button7_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window3;
GtkWidget *treeview1;	
	window3=create_window3();
	gtk_widget_show (window3);

	treeview1=lookup_widget(window3,"treeview1");
	afficher_event(treeview1);
}


void
on_button2_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
	
	window2=create_window2();
	gtk_widget_show (window2);
	

}


void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window11;
GtkWidget *treeview6;
	
	window11=create_window11();
	gtk_widget_show (window11);

	treeview6=lookup_widget(window11,"treeview6");
	afficher_seancec(treeview6);
}


void
on_button4_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window5;
GtkWidget *treeview3;
	
	window5=create_window5();
	gtk_widget_show (window5);
	

	treeview3=lookup_widget(window5,"treeview3");
	afficher_seancee(treeview3);
}


void
on_button5_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window7;
	
	window7=create_window7();
	gtk_widget_show (window7);
}



void
on_button8_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *button8;
GtkWidget *label6;
char nom1[10];
offre offre1;
char str[100];


combobox1=lookup_widget(objet_graphique,"combobox1");
strcpy(nom1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
offre1=getoffre(nom1);
label6=lookup_widget(objet_graphique,"label6");
strcpy(str,"Déscription : ");
strcat(str,offre1.description);
strcat(str,"\nPrix :");
strcat(str,offre1.prix);
gtk_label_set_text(GTK_LABEL(label6),str);

}


void
on_button9_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window4;
	
	window4=create_window4();
	gtk_widget_show (window4);
}


void
on_button12_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label8;
char msg1[60],msg2[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objet_graphique,"entry1");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label8");
s=annulation(id,num);
switch (s)
		{case 0 : {modif_nb1(num);
			   supression_part(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
}


void
on_button11_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label8;
char msg1[60],msg2[60],msg3[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
input1=lookup_widget(objet_graphique,"entry1");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label8");
s=inscription(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb(num);
			   ajout_part(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		}
}


void
on_button13_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window6;
	
	window6=create_window6();
	gtk_widget_show (window6);
}


void
on_button14_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label10;
char msg1[60],msg2[60],msg3[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
input1=lookup_widget(objet_graphique,"entry2");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label10");
s=inscription1(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb2(num);
			   ajout_part1(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		}
}


void
on_button15_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label10;
char msg1[60],msg2[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objet_graphique,"entry2");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label10");
s=annulation1(id,num);
switch (s)
		{case 0 : {modif_nb3(num);
			   supression_part1(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
		
}


void
on_button16_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window8;
GtkWidget *treeview4;
	
	window8=create_window8();
	gtk_widget_show (window8);

	treeview4=lookup_widget(window8,"treeview4");
	afficher_med(treeview4);
}


void
on_button17_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window7;
GtkWidget *window9;
GtkWidget *treeview5;
	
	window9=create_window9();
	gtk_widget_show (window9);
	
	treeview5=lookup_widget(window9,"treeview5");
	afficher_c(treeview5);
}

void
on_button19_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window9;
GtkWidget *window10;
	
	window10=create_window10();
	gtk_widget_show (window10);
}


void
on_button20_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output;
GtkWidget *label13;
char ch[20],msg1[60],msg2[60],msg3[60],note[5],idc[5],ida[5];
int s,s1;
strcpy(ida,"1");//juste pour le test
strcpy(msg1,"Vous avez modifié la note du coach");
strcpy(msg2,"Votre note est prise .Merci" );
strcpy(msg3,"veuillez entrer un id valide du coach");
input1=lookup_widget(objet_graphique,"entry3");
strcpy(idc,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entry4");
strcpy(note,gtk_entry_get_text(GTK_ENTRY(input2)));
output=lookup_widget(objet_graphique,"label13");
s=comparaison_id(idc);
s1=comparaison_id1(idc,ida);
if(s==1)
	{if(s1==1){modif_note(ida,idc,note);
		   gtk_label_set_text(GTK_LABEL(output),msg1);
		  }
	 else {
		ajout_note(ida,idc,note);
	 	gtk_label_set_text(GTK_LABEL(output),msg2);
	      }
	}
else gtk_label_set_text(GTK_LABEL(output),msg3);	   	
}


void
on_button21_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window11;
GtkWidget *window12;
	
	window12=create_window12();
	gtk_widget_show (window12);
	
}


void
on_button22_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label15;
char msg1[60],msg2[60],msg3[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"vous êtes déjà inscrit à cet évenement");
strcpy(msg2,"Désolé le nombre maximal des participants est atteint" );
strcpy(msg3,"Inscription réussite.Vous êtes le bienvenue" );
input1=lookup_widget(objet_graphique,"entry5");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label15");
s=inscription2(id,num);
switch (s)
		{case 0 : {gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case 1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		 case 2 : {modif_nb4(num);
			   ajout_part2(num,id);
			   gtk_label_set_text(GTK_LABEL(output),msg3);
		   	break;
		  	}
		}
}


void
on_button23_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;
GtkWidget *label15;
char msg1[60],msg2[60],num[5],id[5];
int s;
strcpy(id,"1");//juste pour le test
strcpy(msg1,"Vous avez annulé votre inscription");
strcpy(msg2,"Vous n'êtes pas inscrit dans cet évenement" );
input1=lookup_widget(objet_graphique,"entry5");
strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"label15");
s=annulation2(id,num);
switch (s)
		{case 0 : {modif_nb5(num);
			   supression_part2(num);
			gtk_label_set_text(GTK_LABEL(output),msg1);
		  	break;
			}
		 case -1 : {gtk_label_set_text(GTK_LABEL(output),msg2);
		   	break;
		  	}
		}
}

