/*
 * @lc app=leetcode.cn id=606 lang=golang
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(root *TreeNode) string {
	if !root {
		return ""
	}
	buff := strings.Builder
	buff.WriteString(string(root.val))
	if !root.left {
		if !root.right {
			
		}
	}
}
// @lc code=end



$ curl -s -XPOST -H"Content-Type: application/json" -H"Authorization: Bearer $token" -d'{"metadata":{"name":"authztest"},"expires":0,"description":"admin secret"}' http://127.0.0.1:8080/v1/secrets
{"metadata":{"id":23,"name":"authztest","createdAt":"2021-04-08T07:24:50.071671422+08:00","updatedAt":"2021-04-08T07:24:50.071671422+08:00"},"username":"admin","secretID":"ZuxvXNfG08BdEMqkTaP41L2DLArlE6Jpqoox","secretKey":"7Sfa5EfAPIwcTLGCfSvqLf0zZGCjF3l8","expires":0,"description":"admin secret"}
{"metadata":{"id":22,"instanceID":"secret-53e537","name":"authztest","createdAt":"2021-11-20T14:28:09.669+08:00","updatedAt":"2021-11-20T14:28:09.669+08:00"},"username":"admin","secretID":"d1XiNNjcdEL8QXwahHcpkpgvWtclSr6VrxCP","secretKey":"1jJ1E66PuMMJJ5JO6RfIswP2ad8FeNlY","expires":0,"description":"admin secret"}


$ iamctl jwt sign d1XiNNjcdEL8QXwahHcpkpgvWtclSr6VrxCP 1jJ1E66PuMMJJ5JO6RfIswP2ad8FeNlY # iamctl jwt sign $secretID $secretKey
eyJhbGciOiJIUzI1NiIsImtpZCI6Ilp1eHZYTmZHMDhCZEVNcWtUYVA0MUwyRExBcmxFNkpwcW9veCIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJpYW0uYXV0aHoubWFybW90ZWR1LmNvbSIsImV4cCI6MTYxNzg0NTE5NSwiaWF0IjoxNjE3ODM3OTk1LCJpc3MiOiJpYW1jdGwiLCJuYmYiOjE2MTc4Mzc5OTV9.za9yLM7lHVabPAlVQLCqXEaf8sTU6sodAsMXnmpXjMQ

eyJhbGciOiJIUzI1NiIsImtpZCI6ImQxWGlOTmpjZEVMOFFYd2FoSGNwa3Bndld0Y2xTcjZWcnhDUCIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJpYW0uYXV0aHoubWFybW90ZWR1LmNvbSIsImV4cCI6MTYzNzM5NzAwMywiaWF0IjoxNjM3Mzg5ODAzLCJpc3MiOiJpYW1jdGwiLCJuYmYiOjE2MzczODk4MDN9.3YDUF1XOX80AY2SgYYgU0hTBSlyQfVOD37ghoiI2kPE


$ curl -s -XPOST -H'Content-Type: application/json' -H'Authorization: Bearer eyJhbGciOiJIUzI1NiIsImtpZCI6ImQxWGlOTmpjZEVMOFFYd2FoSGNwa3Bndld0Y2xTcjZWcnhDUCIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJpYW0uYXV0aHoubWFybW90ZWR1LmNvbSIsImV4cCI6MTYzNzM5NzAwMywiaWF0IjoxNjM3Mzg5ODAzLCJpc3MiOiJpYW1jdGwiLCJuYmYiOjE2MzczODk4MDN9.3YDUF1XOX80AY2SgYYgU0hTBSlyQfVOD37ghoiI2kPE' -d'{"subject":"users:maria","action":"delete","resource":"resources:articles:ladon-introduction","context":{"remoteIPAddress":"192.168.0.5"}}' http://127.0.0.1:9090/v1/authz
{"allowed":true}


$ cd $IAM_ROOT
$ source scripts/install/environment.sh
$ make build BINS=iam-pump
$ sudo cp _output/platforms/linux/amd64/iam-pump ${IAM_INSTALL_DIR}/bin


$ ./scripts/genconfig.sh scripts/install/environment.sh configs/iam-pump.yaml > iam-pump.yaml
$ sudo mv iam-pump.yaml ${IAM_CONFIG_DIR}


$ ./scripts/genconfig.sh scripts/install/environment.sh init/iam-pump.service > iam-pump.service
$ sudo mv iam-pump.service /etc/systemd/system/


$ sudo systemctl daemon-reload
$ sudo systemctl enable iam-pump
$ sudo systemctl restart iam-pump
$ systemctl status iam-pump # 查看 iam-pump 运行状态，如果输出中包含 active (running)字样说明 iam-pump 成功启动。


$ curl http://127.0.0.1:7070/healthz
{"status": "ok"}


$ cd $IAM_ROOT
$ ./scripts/update-generated-docs.sh


$ sudo cp docs/man/man1/* /usr/share/man/man1/


$ man iam-apiserver