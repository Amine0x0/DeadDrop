package main

import (
    "fmt"
    "io"
    "net/http"
)

func uploadHandler(w http.ResponseWriter, r *http.Request) {
    if r.Method != http.MethodPost {
        http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
        return
    }

    fileData, err := io.ReadAll(r.Body)
    if err != nil {
        http.Error(w, "Failed to read data", http.StatusBadRequest)
        return
    }

    cid := uploadToKubo(fileData) 
    fmt.Printf("Uploaded to IPFS: %s\n", cid)


    txHash := deployToSolana(cid)
    fmt.Printf("Escrow deployed: %s\n", txHash)

    w.WriteHeader(http.StatusOK)
    w.Write([]byte("Success: " + cid))
}

func uploadToKubo(data []byte) string {
	//kubo
    return "QmHashFromKubo123" 
}

func deployToSolana(cid string) string {
	//solana
    return "TxHashFromSolana456"
}

func main() {
    http.HandleFunc("/upload", uploadHandler)
    fmt.Println("Courier (Go) is online and listening on :8080...")
    http.ListenAndServe(":8080", nil)
}