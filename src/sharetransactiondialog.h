/*******************************************************
 Copyright (C) 2016 Stefano Giorgio

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/

#pragma once

#include "model/Model_Stock.h"
#include "model/Model_Translink.h"
#include "model/Model_Shareinfo.h"

class mmDatePickerCtrl;
class mmTextCtrl;
class UserTransactionPanel;

class ShareTransactionDialog : public wxDialog
{
    wxDECLARE_DYNAMIC_CLASS(ShareTransactionDialog);
    wxDECLARE_EVENT_TABLE();

public:
    ShareTransactionDialog();
    ShareTransactionDialog(wxWindow* parent, Model_Stock::Data* stock);
    ShareTransactionDialog(wxWindow* parent, Model_Translink::Data* transfer_entry, Model_Checking::Data* checking_entry);

    int m_stock_id;

private:
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY
        , const wxString& caption = _("Edit Share Transaction")
        , const wxPoint& pos = wxDefaultPosition
        , const wxSize& size = wxDefaultSize
        , long style = wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX);

    void CreateControls();
    void DataToControls();

    double GetAmount(double shares, double price, double commision);
    void OnQuit(wxCloseEvent& WXUNUSED(event));
    void OnOk(wxCommandEvent& WXUNUSED(event));
    void OnCancel(wxCommandEvent& WXUNUSED(event));
    void OnStockPriceButton(wxCommandEvent& event);
    void CalculateAmount(wxCommandEvent& event);

private:
    Model_Stock::Data* m_stock;
    wxTextCtrl* m_stock_name_ctrl;
    mmTextCtrl* m_share_num_ctrl;
    wxTextCtrl* m_stock_symbol_ctrl;
    mmTextCtrl* m_share_price_ctrl;
    wxTextCtrl* m_share_lot_ctrl;
    mmTextCtrl* m_share_commission_ctrl;
    wxTextCtrl* m_notes_ctrl;
    wxBitmapButton* m_attachments_btn;

    UserTransactionPanel* m_transaction_panel;
    wxString m_dialog_heading;

    Model_Checking::Data* m_checking_entry;
    Model_Translink::Data* m_translink_entry;
    Model_Shareinfo::Data* m_share_entry;
    enum
    {
        ID_STOCKTRANS_DATEPICKER_CHANGE = wxID_HIGHEST + 820,
        ID_STOCKTRANS_SHARE_NAME,
        ID_STOCKTRANS_SHARE_SYMBOL,
        ID_STOCKTRANS_SHARE_NUMBER,
        ID_STOCKTRANS_SHARE_PRICE,
        ID_STOCKTRANS_SHARE_LOT,
        ID_STOCKTRANS_SHARE_COMMISSION,
    };
};
