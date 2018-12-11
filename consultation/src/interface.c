/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed1;
  GtkWidget *notebook1;
  GtkWidget *fixed2;
  GtkWidget *label4;
  GtkWidget *button7;
  GtkWidget *button2;
  GtkWidget *button1;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button6;
  GtkWidget *button5;
  GtkWidget *label1;
  GtkWidget *fixed3;
  GtkWidget *label2;
  GtkWidget *fixed4;
  GtkWidget *label3;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window1), GTK_WIN_POS_CENTER);
  gtk_window_set_gravity (GTK_WINDOW (window1), GDK_GRAVITY_CENTER);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  notebook1 = gtk_notebook_new ();
  gtk_widget_show (notebook1);
  gtk_fixed_put (GTK_FIXED (fixed1), notebook1, 0, 0);
  gtk_widget_set_size_request (notebook1, 408, 304);

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed2);

  label4 = gtk_label_new (_("Bonjour "));
  gtk_widget_show (label4);
  gtk_fixed_put (GTK_FIXED (fixed2), label4, 120, 10);
  gtk_widget_set_size_request (label4, 175, 50);

  button7 = gtk_button_new_with_mnemonic (_("D\303\251connexion"));
  gtk_widget_show (button7);
  gtk_fixed_put (GTK_FIXED (fixed2), button7, 280, 232);
  gtk_widget_set_size_request (button7, 120, 40);

  button2 = gtk_button_new_with_mnemonic (_("Offres"));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed2), button2, 220, 50);
  gtk_widget_set_size_request (button2, 150, 50);

  button1 = gtk_button_new_with_mnemonic (_("Evenements"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed2), button1, 50, 50);
  gtk_widget_set_size_request (button1, 150, 50);

  button3 = gtk_button_new_with_mnemonic (_("S\303\251ances de cure"));
  gtk_widget_show (button3);
  gtk_fixed_put (GTK_FIXED (fixed2), button3, 50, 110);
  gtk_widget_set_size_request (button3, 150, 50);

  button4 = gtk_button_new_with_mnemonic (_("         S\303\251ances \nd'entrainements"));
  gtk_widget_show (button4);
  gtk_fixed_put (GTK_FIXED (fixed2), button4, 220, 110);
  gtk_widget_set_size_request (button4, 150, 50);

  button6 = gtk_button_new_with_mnemonic (_("Voir un \nm\303\251decin"));
  gtk_widget_show (button6);
  gtk_fixed_put (GTK_FIXED (fixed2), button6, 220, 170);
  gtk_widget_set_size_request (button6, 150, 50);

  button5 = gtk_button_new_with_mnemonic (_("  Consulter les \nprofils du staff"));
  gtk_widget_show (button5);
  gtk_fixed_put (GTK_FIXED (fixed2), button5, 50, 170);
  gtk_widget_set_size_request (button5, 150, 50);

  label1 = gtk_label_new (_("Acceuil"));
  gtk_widget_show (label1);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 0), label1);

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed3);

  label2 = gtk_label_new (_("Profil"));
  gtk_widget_show (label2);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 1), label2);

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed4);

  label3 = gtk_label_new (_("Notifications"));
  gtk_widget_show (label3);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 2), label3);

  g_signal_connect ((gpointer) button7, "clicked",
                    G_CALLBACK (on_button7_clicked),
                    NULL);
  g_signal_connect ((gpointer) button2, "clicked",
                    G_CALLBACK (on_button2_clicked),
                    NULL);
  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) button3, "clicked",
                    G_CALLBACK (on_button3_clicked),
                    NULL);
  g_signal_connect ((gpointer) button4, "clicked",
                    G_CALLBACK (on_button4_clicked),
                    NULL);
  g_signal_connect ((gpointer) button6, "clicked",
                    G_CALLBACK (on_button6_clicked),
                    NULL);
  g_signal_connect ((gpointer) button5, "clicked",
                    G_CALLBACK (on_button5_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, notebook1, "notebook1");
  GLADE_HOOKUP_OBJECT (window1, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (window1, label4, "label4");
  GLADE_HOOKUP_OBJECT (window1, button7, "button7");
  GLADE_HOOKUP_OBJECT (window1, button2, "button2");
  GLADE_HOOKUP_OBJECT (window1, button1, "button1");
  GLADE_HOOKUP_OBJECT (window1, button3, "button3");
  GLADE_HOOKUP_OBJECT (window1, button4, "button4");
  GLADE_HOOKUP_OBJECT (window1, button6, "button6");
  GLADE_HOOKUP_OBJECT (window1, button5, "button5");
  GLADE_HOOKUP_OBJECT (window1, label1, "label1");
  GLADE_HOOKUP_OBJECT (window1, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (window1, label2, "label2");
  GLADE_HOOKUP_OBJECT (window1, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (window1, label3, "label3");

  return window1;
}

GtkWidget*
create_window2 (void)
{
  GtkWidget *window2;
  GtkWidget *fixed5;
  GtkWidget *combobox1;
  GtkWidget *button8;
  GtkWidget *label5;
  GtkWidget *label6;

  window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window2), _("Offres"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (window2), fixed5);

  combobox1 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox1);
  gtk_fixed_put (GTK_FIXED (fixed5), combobox1, 168, 64);
  gtk_widget_set_size_request (combobox1, 304, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("None"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("1"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("2"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("3"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("4"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("5"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("6"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("7"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("8"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("9"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("10"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("11"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("12"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("13"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("14"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("15"));

  button8 = gtk_button_new_with_mnemonic (_("Consulter l'offre"));
  gtk_widget_show (button8);
  gtk_fixed_put (GTK_FIXED (fixed5), button8, 208, 120);
  gtk_widget_set_size_request (button8, 160, 40);

  label5 = gtk_label_new (_("Nos offres :"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixed5), label5, 48, 72);
  gtk_widget_set_size_request (label5, 112, 32);

  label6 = gtk_label_new ("");
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed5), label6, 24, 176);
  gtk_widget_set_size_request (label6, 504, 160);

  g_signal_connect ((gpointer) button8, "clicked",
                    G_CALLBACK (on_button8_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window2, window2, "window2");
  GLADE_HOOKUP_OBJECT (window2, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (window2, combobox1, "combobox1");
  GLADE_HOOKUP_OBJECT (window2, button8, "button8");
  GLADE_HOOKUP_OBJECT (window2, label5, "label5");
  GLADE_HOOKUP_OBJECT (window2, label6, "label6");

  return window2;
}

GtkWidget*
create_window3 (void)
{
  GtkWidget *window3;
  GtkWidget *fixed6;
  GtkWidget *treeview1;
  GtkWidget *button9;

  window3 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window3), _("Ev\303\251nements"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (window3), fixed6);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed6), treeview1, 0, 0);
  gtk_widget_set_size_request (treeview1, 656, 392);

  button9 = gtk_button_new_with_mnemonic (_("S'inscrire/annuler l'inscription "));
  gtk_widget_show (button9);
  gtk_fixed_put (GTK_FIXED (fixed6), button9, 192, 408);
  gtk_widget_set_size_request (button9, 250, 40);

  g_signal_connect ((gpointer) button9, "clicked",
                    G_CALLBACK (on_button9_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window3, window3, "window3");
  GLADE_HOOKUP_OBJECT (window3, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (window3, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (window3, button9, "button9");

  return window3;
}

GtkWidget*
create_window4 (void)
{
  GtkWidget *window4;
  GtkWidget *fixed7;
  GtkWidget *entry1;
  GtkWidget *button11;
  GtkWidget *button12;
  GtkWidget *label8;
  GtkWidget *label7;

  window4 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window4), _("Inscription/Annulation"));

  fixed7 = gtk_fixed_new ();
  gtk_widget_show (fixed7);
  gtk_container_add (GTK_CONTAINER (window4), fixed7);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed7), entry1, 136, 112);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  button11 = gtk_button_new_with_mnemonic (_("S'inscrire"));
  gtk_widget_show (button11);
  gtk_fixed_put (GTK_FIXED (fixed7), button11, 56, 168);
  gtk_widget_set_size_request (button11, 152, 35);

  button12 = gtk_button_new_with_mnemonic (_("Annuler l'inscription"));
  gtk_widget_show (button12);
  gtk_fixed_put (GTK_FIXED (fixed7), button12, 248, 168);
  gtk_widget_set_size_request (button12, 152, 35);

  label8 = gtk_label_new ("");
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed7), label8, 0, 208);
  gtk_widget_set_size_request (label8, 488, 176);

  label7 = gtk_label_new (_("Veuillez ins\303\251rer le \nnum\303\251ro de \nl'evenement "));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed7), label7, 128, 32);
  gtk_widget_set_size_request (label7, 192, 80);

  g_signal_connect ((gpointer) button11, "clicked",
                    G_CALLBACK (on_button11_clicked),
                    NULL);
  g_signal_connect ((gpointer) button12, "clicked",
                    G_CALLBACK (on_button12_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window4, window4, "window4");
  GLADE_HOOKUP_OBJECT (window4, fixed7, "fixed7");
  GLADE_HOOKUP_OBJECT (window4, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (window4, button11, "button11");
  GLADE_HOOKUP_OBJECT (window4, button12, "button12");
  GLADE_HOOKUP_OBJECT (window4, label8, "label8");
  GLADE_HOOKUP_OBJECT (window4, label7, "label7");

  return window4;
}

GtkWidget*
create_window5 (void)
{
  GtkWidget *window5;
  GtkWidget *fixed8;
  GtkWidget *treeview3;
  GtkWidget *button13;

  window5 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window5), _("S\303\251ances d'entrainement"));

  fixed8 = gtk_fixed_new ();
  gtk_widget_show (fixed8);
  gtk_container_add (GTK_CONTAINER (window5), fixed8);

  treeview3 = gtk_tree_view_new ();
  gtk_widget_show (treeview3);
  gtk_fixed_put (GTK_FIXED (fixed8), treeview3, 0, 0);
  gtk_widget_set_size_request (treeview3, 616, 392);

  button13 = gtk_button_new_with_mnemonic (_("S'inscrire/Annuler l'inscription"));
  gtk_widget_show (button13);
  gtk_fixed_put (GTK_FIXED (fixed8), button13, 192, 408);
  gtk_widget_set_size_request (button13, 250, 40);

  g_signal_connect ((gpointer) button13, "clicked",
                    G_CALLBACK (on_button13_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window5, window5, "window5");
  GLADE_HOOKUP_OBJECT (window5, fixed8, "fixed8");
  GLADE_HOOKUP_OBJECT (window5, treeview3, "treeview3");
  GLADE_HOOKUP_OBJECT (window5, button13, "button13");

  return window5;
}

GtkWidget*
create_window6 (void)
{
  GtkWidget *window6;
  GtkWidget *fixed9;
  GtkWidget *label9;
  GtkWidget *entry2;
  GtkWidget *label10;
  GtkWidget *button14;
  GtkWidget *button15;

  window6 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window6), _("Inscription/Annulation"));

  fixed9 = gtk_fixed_new ();
  gtk_widget_show (fixed9);
  gtk_container_add (GTK_CONTAINER (window6), fixed9);

  label9 = gtk_label_new (_("Veuillez ins\303\251rer le\nnum\303\251ro de s\303\251ance"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed9), label9, 128, 32);
  gtk_widget_set_size_request (label9, 192, 80);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed9), entry2, 136, 112);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  label10 = gtk_label_new ("");
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed9), label10, 0, 200);
  gtk_widget_set_size_request (label10, 482, 176);

  button14 = gtk_button_new_with_mnemonic (_("S'inscrire"));
  gtk_widget_show (button14);
  gtk_fixed_put (GTK_FIXED (fixed9), button14, 56, 168);
  gtk_widget_set_size_request (button14, 152, 35);

  button15 = gtk_button_new_with_mnemonic (_("Annuler l'inscription"));
  gtk_widget_show (button15);
  gtk_fixed_put (GTK_FIXED (fixed9), button15, 248, 168);
  gtk_widget_set_size_request (button15, 152, 35);

  g_signal_connect ((gpointer) button14, "clicked",
                    G_CALLBACK (on_button14_clicked),
                    NULL);
  g_signal_connect ((gpointer) button15, "clicked",
                    G_CALLBACK (on_button15_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window6, window6, "window6");
  GLADE_HOOKUP_OBJECT (window6, fixed9, "fixed9");
  GLADE_HOOKUP_OBJECT (window6, label9, "label9");
  GLADE_HOOKUP_OBJECT (window6, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (window6, label10, "label10");
  GLADE_HOOKUP_OBJECT (window6, button14, "button14");
  GLADE_HOOKUP_OBJECT (window6, button15, "button15");

  return window6;
}

GtkWidget*
create_window7 (void)
{
  GtkWidget *window7;
  GtkWidget *fixed10;
  GtkWidget *button16;
  GtkWidget *button17;

  window7 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (window7, 400, 350);
  gtk_window_set_title (GTK_WINDOW (window7), _("Consultation du staff"));

  fixed10 = gtk_fixed_new ();
  gtk_widget_show (fixed10);
  gtk_container_add (GTK_CONTAINER (window7), fixed10);

  button16 = gtk_button_new_with_mnemonic (_("Nos m\303\251decins"));
  gtk_widget_show (button16);
  gtk_fixed_put (GTK_FIXED (fixed10), button16, 100, 50);
  gtk_widget_set_size_request (button16, 208, 48);

  button17 = gtk_button_new_with_mnemonic (_("Nos coachs"));
  gtk_widget_show (button17);
  gtk_fixed_put (GTK_FIXED (fixed10), button17, 100, 120);
  gtk_widget_set_size_request (button17, 208, 40);

  g_signal_connect ((gpointer) button16, "clicked",
                    G_CALLBACK (on_button16_clicked),
                    NULL);
  g_signal_connect ((gpointer) button17, "clicked",
                    G_CALLBACK (on_button17_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window7, window7, "window7");
  GLADE_HOOKUP_OBJECT (window7, fixed10, "fixed10");
  GLADE_HOOKUP_OBJECT (window7, button16, "button16");
  GLADE_HOOKUP_OBJECT (window7, button17, "button17");

  return window7;
}

GtkWidget*
create_window8 (void)
{
  GtkWidget *window8;
  GtkWidget *fixed11;
  GtkWidget *treeview4;

  window8 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window8), _("Liste des m\303\251decins"));

  fixed11 = gtk_fixed_new ();
  gtk_widget_show (fixed11);
  gtk_container_add (GTK_CONTAINER (window8), fixed11);

  treeview4 = gtk_tree_view_new ();
  gtk_widget_show (treeview4);
  gtk_fixed_put (GTK_FIXED (fixed11), treeview4, 0, 0);
  gtk_widget_set_size_request (treeview4, 800, 504);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window8, window8, "window8");
  GLADE_HOOKUP_OBJECT (window8, fixed11, "fixed11");
  GLADE_HOOKUP_OBJECT (window8, treeview4, "treeview4");

  return window8;
}

GtkWidget*
create_window9 (void)
{
  GtkWidget *window9;
  GtkWidget *fixed12;
  GtkWidget *treeview5;
  GtkWidget *button19;

  window9 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window9), _("Liste des coachs"));

  fixed12 = gtk_fixed_new ();
  gtk_widget_show (fixed12);
  gtk_container_add (GTK_CONTAINER (window9), fixed12);

  treeview5 = gtk_tree_view_new ();
  gtk_widget_show (treeview5);
  gtk_fixed_put (GTK_FIXED (fixed12), treeview5, 0, 0);
  gtk_widget_set_size_request (treeview5, 568, 336);

  button19 = gtk_button_new_with_mnemonic (_("Noter un coach"));
  gtk_widget_show (button19);
  gtk_fixed_put (GTK_FIXED (fixed12), button19, 200, 344);
  gtk_widget_set_size_request (button19, 160, 40);

  g_signal_connect ((gpointer) button19, "clicked",
                    G_CALLBACK (on_button19_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window9, window9, "window9");
  GLADE_HOOKUP_OBJECT (window9, fixed12, "fixed12");
  GLADE_HOOKUP_OBJECT (window9, treeview5, "treeview5");
  GLADE_HOOKUP_OBJECT (window9, button19, "button19");

  return window9;
}

GtkWidget*
create_window10 (void)
{
  GtkWidget *window10;
  GtkWidget *fixed13;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *button20;
  GtkWidget *label13;

  window10 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window10), _("Noter un coach"));

  fixed13 = gtk_fixed_new ();
  gtk_widget_show (fixed13);
  gtk_container_add (GTK_CONTAINER (window10), fixed13);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed13), entry3, 152, 48);
  gtk_widget_set_size_request (entry3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed13), entry4, 152, 104);
  gtk_widget_set_size_request (entry4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  label11 = gtk_label_new (_("id coach:"));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed13), label11, 40, 56);
  gtk_widget_set_size_request (label11, 97, 17);

  label12 = gtk_label_new (_("Note sur 10 :"));
  gtk_widget_show (label12);
  gtk_fixed_put (GTK_FIXED (fixed13), label12, 40, 104);
  gtk_widget_set_size_request (label12, 104, 32);

  button20 = gtk_button_new_with_mnemonic (_("Valider"));
  gtk_widget_show (button20);
  gtk_fixed_put (GTK_FIXED (fixed13), button20, 144, 152);
  gtk_widget_set_size_request (button20, 76, 29);

  label13 = gtk_label_new ("");
  gtk_widget_show (label13);
  gtk_fixed_put (GTK_FIXED (fixed13), label13, 0, 184);
  gtk_widget_set_size_request (label13, 400, 120);

  g_signal_connect ((gpointer) button20, "clicked",
                    G_CALLBACK (on_button20_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window10, window10, "window10");
  GLADE_HOOKUP_OBJECT (window10, fixed13, "fixed13");
  GLADE_HOOKUP_OBJECT (window10, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (window10, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (window10, label11, "label11");
  GLADE_HOOKUP_OBJECT (window10, label12, "label12");
  GLADE_HOOKUP_OBJECT (window10, button20, "button20");
  GLADE_HOOKUP_OBJECT (window10, label13, "label13");

  return window10;
}

