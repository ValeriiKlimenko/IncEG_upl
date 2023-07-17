{
  TFile f("resRC.root");
  TH1F *cs[20];
  TH1F *csRC[20];
  TH1F *RC[20];
  for (int q = 0; q < 20; q++){
    cs[q] = (TH1F*) f.Get(Form("csQ%d", q + 1));
    csRC[q] = (TH1F*) f.Get(Form("csRCQ%d", q + 1));
    RC[q] = (TH1F*) f.Get(Form("RCQ%d", q + 1));
  }
  TCanvas *aaa = new TCanvas("aaa", "aaa", 10, 10, 1000, 800);
  aaa->Divide(5, 4);
  for (int q = 0; q < 20; q++){
    aaa->cd(q + 1);
    cs[q]->Draw();
    cs[q]->SetLineColor(1);
    cs[q]->SetAxisRange(1, 4, "x");
    csRC[q]->Draw("same");
    csRC[q]->SetLineColor(2);
  }
  aaa->SaveAs("cs.pdf");

  for (int q = 0; q < 20; q++){
    aaa->cd(q + 1);
    RC[q]->Draw();
    RC[q]->SetLineColor(1);
    RC[q]->SetAxisRange(1, 4, "x");
  }
  aaa->SaveAs("rc.pdf");

}
