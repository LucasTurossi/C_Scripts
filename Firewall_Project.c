#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>


void packet_handler(unsigned char *user_data, const struct pcap_pkthdr *pkthdr, const unsigned char *packet) {
    printf("Captured a packet of length %d\n", pkthdr->len);

const unsigned char *ethernet_header = packet;
    int ether_type = ntohs((ethernet_header[12] << 8) | ethernet_header[13]);


if (ether_type == 0x0800){
    const unsigned char *ip_header = packet + 14;
    int ip_version = (ip_header[0] >> 4) & 0xF;
    if (ip_version == 4 ){
        int ip_header_length = (ip_header[0] & 0xF) *4;
        struct in_addr src_ip, dst_ip;
        memcpy(&src_ip, ip_header + 12, sizeof(struct in_addr));
        memcpy(&dst_ip, ip_header + 16, sizeof(struct in_addr));

        printf("Source IP: %s\n", inet_ntoa(src_ip));
        printf("Destination IP: %s\n", inet_ntoa(dst_ip));
        }       
    }
}



int main(void){
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL){
        fprintf(stderr, "Error opening the interface: %s\n", errbuf);
        return 1;
    }

    struct bpf_program fp;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1){
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1){
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}