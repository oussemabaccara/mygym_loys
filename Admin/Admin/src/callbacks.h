#include <gtk/gtk.h>


void on_button_clicked(GtkWidget       *objet_graphique,gpointer         user_data);



void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_activ_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_stats_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_deals_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_admin_list_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_activ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_stats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_deals_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_list_add_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_list_return_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_return_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_ajouter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_activ_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_activ_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_list_upd_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_deals_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_deals_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_search_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_edit_acc_return_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_EDIT_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_des_acc_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_activ_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_add_activ_return_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeactiv_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_edit_ev_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_edev_return_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_activ_edit_show                     (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_delev_clicked                       (GtkButton       *objet,
                                        gpointer         user_data);
